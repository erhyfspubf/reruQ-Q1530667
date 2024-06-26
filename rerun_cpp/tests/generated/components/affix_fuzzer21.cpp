// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/components/fuzzy.fbs".

#include "affix_fuzzer21.hpp"

#include "../datatypes/affix_fuzzer21.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun::components {}

namespace rerun {
    const std::shared_ptr<arrow::DataType>& Loggable<components::AffixFuzzer21>::arrow_datatype() {
        static const auto datatype = Loggable<rerun::datatypes::AffixFuzzer21>::arrow_datatype();
        return datatype;
    }

    rerun::Error Loggable<components::AffixFuzzer21>::fill_arrow_array_builder(
        arrow::StructBuilder* builder, const components::AffixFuzzer21* elements,
        size_t num_elements
    ) {
        static_assert(sizeof(rerun::datatypes::AffixFuzzer21) == sizeof(components::AffixFuzzer21));
        RR_RETURN_NOT_OK(Loggable<rerun::datatypes::AffixFuzzer21>::fill_arrow_array_builder(
            builder,
            reinterpret_cast<const rerun::datatypes::AffixFuzzer21*>(elements),
            num_elements
        ));

        return Error::ok();
    }

    Result<std::shared_ptr<arrow::Array>> Loggable<components::AffixFuzzer21>::to_arrow(
        const components::AffixFuzzer21* instances, size_t num_instances
    ) {
        // TODO(andreas): Allow configuring the memory pool.
        arrow::MemoryPool* pool = arrow::default_memory_pool();
        auto datatype = arrow_datatype();

        ARROW_ASSIGN_OR_RAISE(auto builder, arrow::MakeBuilder(datatype, pool))
        if (instances && num_instances > 0) {
            RR_RETURN_NOT_OK(Loggable<components::AffixFuzzer21>::fill_arrow_array_builder(
                static_cast<arrow::StructBuilder*>(builder.get()),
                instances,
                num_instances
            ));
        }
        std::shared_ptr<arrow::Array> array;
        ARROW_RETURN_NOT_OK(builder->Finish(&array));
        return array;
    }
} // namespace rerun
