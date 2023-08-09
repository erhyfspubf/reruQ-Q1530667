// NOTE: This file was autogenerated by re_types_builder; DO NOT EDIT.
// Based on "crates/re_types/definitions/rerun/datatypes/rotation_axis_angle.fbs"

#include "rotation_axis_angle.hpp"

#include "../datatypes/angle.hpp"
#include "../datatypes/vec3d.hpp"

#include <arrow/api.h>

namespace rerun {
    namespace datatypes {
        const std::shared_ptr<arrow::DataType>& RotationAxisAngle::to_arrow_datatype() {
            static const auto datatype = arrow::struct_({
                arrow::field("axis", rerun::datatypes::Vec3D::to_arrow_datatype(), false, nullptr),
                arrow::field("angle", rerun::datatypes::Angle::to_arrow_datatype(), false, nullptr),
            });
            return datatype;
        }

        arrow::Result<std::shared_ptr<arrow::StructBuilder>>
            RotationAxisAngle::new_arrow_array_builder(arrow::MemoryPool* memory_pool) {
            if (!memory_pool) {
                return arrow::Status::Invalid("Memory pool is null.");
            }

            return arrow::Result(std::make_shared<arrow::StructBuilder>(
                to_arrow_datatype(),
                memory_pool,
                std::vector<std::shared_ptr<arrow::ArrayBuilder>>({
                    rerun::datatypes::Vec3D::new_arrow_array_builder(memory_pool).ValueOrDie(),
                    rerun::datatypes::Angle::new_arrow_array_builder(memory_pool).ValueOrDie(),
                })
            ));
        }

        arrow::Status RotationAxisAngle::fill_arrow_array_builder(
            arrow::StructBuilder* builder, const RotationAxisAngle* elements, size_t num_elements
        ) {
            if (!builder) {
                return arrow::Status::Invalid("Passed array builder is null.");
            }
            if (!elements) {
                return arrow::Status::Invalid("Cannot serialize null pointer to arrow array.");
            }

            return arrow::Status::NotImplemented(
                "TODO(andreas): extensions in structs are not yet supported"
            );
            return arrow::Status::NotImplemented(
                "TODO(andreas): extensions in structs are not yet supported"
            );
            ARROW_RETURN_NOT_OK(builder->AppendValues(num_elements, nullptr));

            return arrow::Status::OK();
        }
    } // namespace datatypes
} // namespace rerun