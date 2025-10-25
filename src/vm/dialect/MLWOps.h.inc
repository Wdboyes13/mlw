/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MLWDialect.td                                                        *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlw {
class ImplibsOp;
} // namespace mlw
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlw {

//===----------------------------------------------------------------------===//
// ::mlw::ImplibsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ImplibsOpGenericAdaptorBase {
public:
  struct Properties {
    using librariesTy = ::mlir::ArrayAttr;
    librariesTy libraries;

    auto getLibraries() {
      auto &propStorage = this->libraries;
      return ::llvm::cast<::mlir::ArrayAttr>(propStorage);
    }
    void setLibraries(const ::mlir::ArrayAttr &propValue) {
      this->libraries = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.libraries == this->libraries &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ImplibsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("mlw.implibs", odsAttrs.getContext());
  }

  ImplibsOpGenericAdaptorBase(ImplibsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::ArrayAttr getLibrariesAttr() {
    auto attr = ::llvm::cast<::mlir::ArrayAttr>(getProperties().libraries);
    return attr;
  }

  ::mlir::ArrayAttr getLibraries();
};
} // namespace detail
template <typename RangeT>
class ImplibsOpGenericAdaptor : public detail::ImplibsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ImplibsOpGenericAdaptorBase;
public:
  ImplibsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ImplibsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ImplibsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ImplibsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ImplibsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ImplibsOpGenericAdaptor(RangeT values, const ImplibsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ImplibsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ImplibsOp>>>
  ImplibsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ImplibsOpAdaptor : public ImplibsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ImplibsOpGenericAdaptor::ImplibsOpGenericAdaptor;
  ImplibsOpAdaptor(ImplibsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ImplibsOp : public ::mlir::Op<ImplibsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ImplibsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ImplibsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("libraries")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getLibrariesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getLibrariesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("mlw.implibs");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::ArrayAttr getLibrariesAttr() {
    return ::llvm::cast<::mlir::ArrayAttr>(getProperties().libraries);
  }

  ::mlir::ArrayAttr getLibraries();
  void setLibrariesAttr(::mlir::ArrayAttr attr) {
    getProperties().libraries = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ArrayAttr libraries);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ArrayAttr libraries);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace mlw
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlw::ImplibsOp)


#endif  // GET_OP_CLASSES

