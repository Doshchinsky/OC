#include "/usr/include/llvm/Support/CommandLine.h"
#include "/usr/include/llvm/Support/Host.h"
#include "/usr/include/clang/AST/ASTContext.h"
#include "/usr/include/clang/AST/ASTConsumer.h"
#include "/usr/include/clang/Basic/Diagnostic.h"
#include "/usr/include/clang/Basic/DiagnosticOptions.h"
#include "/usr/include/clang/Basic/FileManager.h"
#include "/usr/include/clang/Basic/SourceManager.h"
#include "/usr/include/clang/Basic/LangOptions.h"
#include "/usr/include/clang/Basic/TargetInfo.h"
#include "/usr/include/clang/Basic/TargetOptions.h"
#include "/usr/include/clang/Frontend/ASTConsumers.h"
#include "/usr/include/clang/Frontend/CompilerInstance.h"
#include "/usr/include/clang/Frontend/TextDiagnosticPrinter.h"
#include "/usr/include/clang/Lex/Preprocessor.h"
#include "/usr/include/clang/Parse/Parser.h"
#include "/usr/include/clang/Parse/ParseAST.h"

#include <iostream>
using namespace llvm;
using namespace clang;
static cl::opt<std::string> FileName(cl::Positional, cl::desc("Input file"), cl::Required);

int main(int argc, char** argv)
{
  cl::ParseCommandLineOptions(argc, argv, "My FE\n");

  CompilerInstance CI;
  DiagnosticOptions diagnosticOptions;
  CI.createDiagnostics();

  std::shared_ptr<clang::TargetOptions> PTO = std::make_shared<clang::TargetOptions>();
  PTO->Triple = llvm::sys::getDefaultTargetTriple();
  TargetInfo *PTI = clang::TargetInfo::CreateTargetInfo(CI.getDiagnostics(), PTO);
  CI.setTarget(PTI);

  CI.createFileManager();
  CI.createSourceManager(CI.getFileManager());
  CI.createPreprocessor(clang::TranslationUnitKind::TU_Complete);
  CI.getPreprocessorOpts();

  std::unique_ptr< clang::ASTConsumer > astConsumer = clang::CreateASTPrinter(NULL, "");
  CI.setASTConsumer(std::move(astConsumer));

  CI.createASTContext();
  CI.createSema(TU_Complete, NULL);
  const clang::FileEntry *pFile = CI.getFileManager().getFile(FileName);
  if (!pFile) {
   std::cerr << "File not found: " << FileName << std::endl;
   return 1;
  }
  FileID mainFileID = CI.getSourceManager().createFileID(pFile,clang::SourceLocation(), clang::SrcMgr::C_User);

  CI.getSourceManager().setMainFileID(mainFileID);
  CI.getDiagnosticClient().BeginSourceFile(CI.getLangOpts(), 0);
  ParseAST(CI.getSema());

  CI.getASTContext().PrintStats();
  CI.getASTContext().Idents.PrintStats();

  return 0;
}
