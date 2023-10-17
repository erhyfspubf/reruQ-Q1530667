// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/rotation3d.fbs".

#include "rotation3d.hpp"

#include "quaternion.hpp"
#include "rotation_axis_angle.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace datatypes {
        const std::shared_ptr<arrow::DataType> &Rotation3D::arrow_datatype() {
            static const auto datatype = arrow::dense_union({
                arrow::field("_null_markers", arrow::null(), true, nullptr),
                arrow::field("Quaternion", rerun::datatypes::Quaternion::arrow_datatype(), false),
                arrow::field(
                    "AxisAngle",
                    rerun::datatypes::RotationAxisAngle::arrow_datatype(),
                    false
                ),
            });
            return datatype;
        }

        Result<std::shared_ptr<arrow::DenseUnionBuilder>> Rotation3D::new_arrow_array_builder(
            arrow::MemoryPool *memory_pool
        ) {
            if (memory_pool == nullptr) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::DenseUnionBuilder>(
                memory_pool,
                // Children:
                std::vector<std::shared_ptr<arrow::ArrayBuilder>>({
                    std::make_shared<arrow::NullBuilder>(memory_pool),
                    rerun::datatypes::Quaternion::new_arrow_array_builder(memory_pool).value,
                    rerun::datatypes::RotationAxisAngle::new_arrow_array_builder(memory_pool).value,
                }),
                arrow_datatype()
            ));
        }

        Error Rotation3D::fill_arrow_array_builder(
            arrow::DenseUnionBuilder *builder, const Rotation3D *elements, size_t num_elements
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

            ARROW_RETURN_NOT_OK(builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                const auto &union_instance = elements[elem_idx];
                ARROW_RETURN_NOT_OK(builder->Append(static_cast<int8_t>(union_instance._tag)));

                auto variant_index = static_cast<int>(union_instance._tag);
                auto variant_builder_untyped = builder->child_builder(variant_index).get();

                switch (union_instance._tag) {
                    case detail::Rotation3DTag::NONE: {
                        ARROW_RETURN_NOT_OK(variant_builder_untyped->AppendNull());
                        break;
                    }
                    case detail::Rotation3DTag::Quaternion: {
                        auto variant_builder =
                            static_cast<arrow::FixedSizeListBuilder *>(variant_builder_untyped);
                        RR_RETURN_NOT_OK(rerun::datatypes::Quaternion::fill_arrow_array_builder(
                            variant_builder,
                            &union_instance._data.quaternion,
                            1
                        ));
                        break;
                    }
                    case detail::Rotation3DTag::AxisAngle: {
                        auto variant_builder =
                            static_cast<arrow::StructBuilder *>(variant_builder_untyped);
                        RR_RETURN_NOT_OK(
                            rerun::datatypes::RotationAxisAngle::fill_arrow_array_builder(
                                variant_builder,
                                &union_instance._data.axis_angle,
                                1
                            )
                        );
                        break;
                    }
                }
            }

            return Error::ok();
        }
    } // namespace datatypes
} // namespace rerun
