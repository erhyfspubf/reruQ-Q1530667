// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/blueprint/datatypes/legend.fbs".

#pragma once

#include "../../result.hpp"

#include <cstdint>
#include <memory>
#include <optional>

namespace arrow {
    class Array;
    class DataType;
    class StructBuilder;
} // namespace arrow

namespace rerun::blueprint::datatypes {
    /// **Datatype**: Configuration for the legend of a plot.
    struct Legend {
        /// Whether or not the legend should be displayed.
        bool visible;

        /// Where should the legend be located.
        ///
        /// Allowed values:
        ///  - LeftTop = 1,
        ///  - RightTop = 2,
        ///  - LeftBottom = 3,
        ///  - RightBottom = 4
        std::optional<uint8_t> location;

      public:
        Legend() = default;
    };
} // namespace rerun::blueprint::datatypes

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<blueprint::datatypes::Legend> {
        static constexpr const char Name[] = "rerun.blueprint.datatypes.Legend";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StructBuilder* builder, const blueprint::datatypes::Legend* elements,
            size_t num_elements
        );

        /// Serializes an array of `rerun::blueprint:: datatypes::Legend` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const blueprint::datatypes::Legend* instances, size_t num_instances
        );
    };
} // namespace rerun
