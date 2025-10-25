/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MLWDialect.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlw {

class MLWDialect : public ::mlir::Dialect {
  explicit MLWDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~MLWDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("mlw");
  }
};
} // namespace mlw
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlw::MLWDialect)
