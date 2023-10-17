// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/view_coordinates.fbs".

#include "view_coordinates.hpp"

#include "../arrow.hpp"

#include <arrow/builder.h>
#include <arrow/table.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace components {
        const char ViewCoordinates::NAME[] = "rerun.components.ViewCoordinates";

        const std::shared_ptr<arrow::DataType> &ViewCoordinates::arrow_datatype() {
            static const auto datatype =
                arrow::fixed_size_list(arrow::field("item", arrow::uint8(), false), 3);
            return datatype;
        }

        Result<std::shared_ptr<arrow::FixedSizeListBuilder>>
            ViewCoordinates::new_arrow_array_builder(arrow::MemoryPool *memory_pool) {
            if (memory_pool == nullptr) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::FixedSizeListBuilder>(
                memory_pool,
                std::make_shared<arrow::UInt8Builder>(memory_pool),
                3
            ));
        }

        Error ViewCoordinates::fill_arrow_array_builder(
            arrow::FixedSizeListBuilder *builder, const ViewCoordinates *elements,
            size_t num_elements
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

            auto value_builder = static_cast<arrow::UInt8Builder *>(builder->value_builder());

            ARROW_RETURN_NOT_OK(builder->AppendValues(static_cast<int64_t>(num_elements)));
            static_assert(sizeof(elements[0].coordinates) == sizeof(elements[0]));
            ARROW_RETURN_NOT_OK(value_builder->AppendValues(
                elements[0].coordinates,
                static_cast<int64_t>(num_elements * 3),
                nullptr
            ));

            return Error::ok();
        }

        Result<rerun::DataCell> ViewCoordinates::to_data_cell(
            const ViewCoordinates *instances, size_t num_instances
        ) {
            // TODO(andreas): Allow configuring the memory pool.
            arrow::MemoryPool *pool = arrow::default_memory_pool();

            auto builder_result = ViewCoordinates::new_arrow_array_builder(pool);
            RR_RETURN_NOT_OK(builder_result.error);
            auto builder = std::move(builder_result.value);
            if (instances && num_instances > 0) {
                RR_RETURN_NOT_OK(ViewCoordinates::fill_arrow_array_builder(
                    builder.get(),
                    instances,
                    num_instances
                ));
            }
            std::shared_ptr<arrow::Array> array;
            ARROW_RETURN_NOT_OK(builder->Finish(&array));

            auto schema = arrow::schema(
                {arrow::field(ViewCoordinates::NAME, ViewCoordinates::arrow_datatype(), false)}
            );

            rerun::DataCell cell;
            cell.component_name = ViewCoordinates::NAME;
            const auto ipc_result = rerun::ipc_from_table(*arrow::Table::Make(schema, {array}));
            RR_RETURN_NOT_OK(ipc_result.error);
            cell.buffer = std::move(ipc_result.value);

            return cell;
        }
    } // namespace components
} // namespace rerun
