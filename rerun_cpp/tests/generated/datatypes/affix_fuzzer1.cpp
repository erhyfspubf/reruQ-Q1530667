// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/datatypes/fuzzy.fbs".

#include "affix_fuzzer1.hpp"

#include "flattened_scalar.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace datatypes {
        const std::shared_ptr<arrow::DataType> &AffixFuzzer1::arrow_datatype() {
            static const auto datatype = arrow::struct_({
                arrow::field("single_float_optional", arrow::float32(), true),
                arrow::field("single_string_required", arrow::utf8(), false),
                arrow::field("single_string_optional", arrow::utf8(), true),
                arrow::field(
                    "many_floats_optional",
                    arrow::list(arrow::field("item", arrow::float32(), false)),
                    true
                ),
                arrow::field(
                    "many_strings_required",
                    arrow::list(arrow::field("item", arrow::utf8(), false)),
                    false
                ),
                arrow::field(
                    "many_strings_optional",
                    arrow::list(arrow::field("item", arrow::utf8(), false)),
                    true
                ),
                arrow::field("flattened_scalar", arrow::float32(), false),
                arrow::field(
                    "almost_flattened_scalar",
                    rerun::datatypes::FlattenedScalar::arrow_datatype(),
                    false
                ),
                arrow::field("from_parent", arrow::boolean(), true),
            });
            return datatype;
        }

        Result<std::shared_ptr<arrow::StructBuilder>> AffixFuzzer1::new_arrow_array_builder(
            arrow::MemoryPool *memory_pool
        ) {
            if (memory_pool == nullptr) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::StructBuilder>(
                arrow_datatype(),
                memory_pool,
                std::vector<std::shared_ptr<arrow::ArrayBuilder>>({
                    std::make_shared<arrow::FloatBuilder>(memory_pool),
                    std::make_shared<arrow::StringBuilder>(memory_pool),
                    std::make_shared<arrow::StringBuilder>(memory_pool),
                    std::make_shared<arrow::ListBuilder>(
                        memory_pool,
                        std::make_shared<arrow::FloatBuilder>(memory_pool)
                    ),
                    std::make_shared<arrow::ListBuilder>(
                        memory_pool,
                        std::make_shared<arrow::StringBuilder>(memory_pool)
                    ),
                    std::make_shared<arrow::ListBuilder>(
                        memory_pool,
                        std::make_shared<arrow::StringBuilder>(memory_pool)
                    ),
                    std::make_shared<arrow::FloatBuilder>(memory_pool),
                    rerun::datatypes::FlattenedScalar::new_arrow_array_builder(memory_pool).value,
                    std::make_shared<arrow::BooleanBuilder>(memory_pool),
                })
            ));
        }

        Error AffixFuzzer1::fill_arrow_array_builder(
            arrow::StructBuilder *builder, const AffixFuzzer1 *elements, size_t num_elements
        ) {
            if (builder == nullptr) {
                return Error(ErrorCode::UnexpectedNullArgument, "Passed array builder is null.");
            }
            if (elements == nullptr) {
                return Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Cannot serialize null pointer to arrow array."
                );
            }

            {
                auto field_builder = static_cast<arrow::FloatBuilder *>(builder->field_builder(0));
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    const auto &element = elements[elem_idx];
                    if (element.single_float_optional.has_value()) {
                        ARROW_RETURN_NOT_OK(
                            field_builder->Append(element.single_float_optional.value())
                        );
                    } else {
                        ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                    }
                }
            }
            {
                auto field_builder = static_cast<arrow::StringBuilder *>(builder->field_builder(1));
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    ARROW_RETURN_NOT_OK(
                        field_builder->Append(elements[elem_idx].single_string_required)
                    );
                }
            }
            {
                auto field_builder = static_cast<arrow::StringBuilder *>(builder->field_builder(2));
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    const auto &element = elements[elem_idx];
                    if (element.single_string_optional.has_value()) {
                        ARROW_RETURN_NOT_OK(
                            field_builder->Append(element.single_string_optional.value())
                        );
                    } else {
                        ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                    }
                }
            }
            {
                auto field_builder = static_cast<arrow::ListBuilder *>(builder->field_builder(3));
                auto value_builder =
                    static_cast<arrow::FloatBuilder *>(field_builder->value_builder());
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                ARROW_RETURN_NOT_OK(value_builder->Reserve(static_cast<int64_t>(num_elements * 1)));

                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    const auto &element = elements[elem_idx];
                    if (element.many_floats_optional.has_value()) {
                        ARROW_RETURN_NOT_OK(field_builder->Append());
                        ARROW_RETURN_NOT_OK(value_builder->AppendValues(
                            element.many_floats_optional.value().data(),
                            static_cast<int64_t>(element.many_floats_optional.value().size()),
                            nullptr
                        ));
                    } else {
                        ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                    }
                }
            }
            {
                auto field_builder = static_cast<arrow::ListBuilder *>(builder->field_builder(4));
                auto value_builder =
                    static_cast<arrow::StringBuilder *>(field_builder->value_builder());
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                ARROW_RETURN_NOT_OK(value_builder->Reserve(static_cast<int64_t>(num_elements * 2)));

                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    const auto &element = elements[elem_idx];
                    ARROW_RETURN_NOT_OK(field_builder->Append());
                    for (size_t item_idx = 0; item_idx < element.many_strings_required.size();
                         item_idx += 1) {
                        ARROW_RETURN_NOT_OK(
                            value_builder->Append(element.many_strings_required[item_idx])
                        );
                    }
                }
            }
            {
                auto field_builder = static_cast<arrow::ListBuilder *>(builder->field_builder(5));
                auto value_builder =
                    static_cast<arrow::StringBuilder *>(field_builder->value_builder());
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                ARROW_RETURN_NOT_OK(value_builder->Reserve(static_cast<int64_t>(num_elements * 1)));

                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    const auto &element = elements[elem_idx];
                    if (element.many_strings_optional.has_value()) {
                        ARROW_RETURN_NOT_OK(field_builder->Append());
                        for (size_t item_idx = 0;
                             item_idx < element.many_strings_optional.value().size();
                             item_idx += 1) {
                            ARROW_RETURN_NOT_OK(value_builder->Append(
                                element.many_strings_optional.value()[item_idx]
                            ));
                        }
                    } else {
                        ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                    }
                }
            }
            {
                auto field_builder = static_cast<arrow::FloatBuilder *>(builder->field_builder(6));
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    ARROW_RETURN_NOT_OK(field_builder->Append(elements[elem_idx].flattened_scalar));
                }
            }
            {
                auto field_builder = static_cast<arrow::StructBuilder *>(builder->field_builder(7));
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    RR_RETURN_NOT_OK(rerun::datatypes::FlattenedScalar::fill_arrow_array_builder(
                        field_builder,
                        &elements[elem_idx].almost_flattened_scalar,
                        1
                    ));
                }
            }
            {
                auto field_builder =
                    static_cast<arrow::BooleanBuilder *>(builder->field_builder(8));
                ARROW_RETURN_NOT_OK(field_builder->Reserve(static_cast<int64_t>(num_elements)));
                for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                    const auto &element = elements[elem_idx];
                    if (element.from_parent.has_value()) {
                        ARROW_RETURN_NOT_OK(field_builder->Append(element.from_parent.value()));
                    } else {
                        ARROW_RETURN_NOT_OK(field_builder->AppendNull());
                    }
                }
            }
            ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements), nullptr));

            return Error::ok();
        }
    } // namespace datatypes
} // namespace rerun
