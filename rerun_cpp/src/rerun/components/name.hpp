// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/name.fbs".

#pragma once

#include "../datatypes/utf8.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>
#include <string>
#include <utility>

namespace arrow {
    class Array;
    class DataType;
    class StringBuilder;
} // namespace arrow

namespace rerun::components {
    /// **Component**: A display name, typically for an entity or a item like a plot series.
    struct Name {
        rerun::datatypes::Utf8 value;

      public:
        // Extensions to generated type defined in 'name_ext.cpp'

        /// Construct `Name` from a null-terminated UTF8 string.
        Name(const char* str) : value(str) {}

        const char* c_str() const {
            return value.c_str();
        }

      public:
        Name() = default;

        Name(rerun::datatypes::Utf8 value_) : value(std::move(value_)) {}

        Name& operator=(rerun::datatypes::Utf8 value_) {
            value = std::move(value_);
            return *this;
        }

        Name(std::string value_) : value(std::move(value_)) {}

        Name& operator=(std::string value_) {
            value = std::move(value_);
            return *this;
        }

        /// Cast to the underlying Utf8 datatype
        operator rerun::datatypes::Utf8() const {
            return value;
        }
    };
} // namespace rerun::components

namespace rerun {
    template <typename T>
    struct Loggable;

    /// \private
    template <>
    struct Loggable<components::Name> {
        static constexpr const char Name[] = "rerun.components.Name";

        /// Returns the arrow data type this type corresponds to.
        static const std::shared_ptr<arrow::DataType>& arrow_datatype();

        /// Fills an arrow array builder with an array of this type.
        static rerun::Error fill_arrow_array_builder(
            arrow::StringBuilder* builder, const components::Name* elements, size_t num_elements
        );

        /// Serializes an array of `rerun::components::Name` into an arrow array.
        static Result<std::shared_ptr<arrow::Array>> to_arrow(
            const components::Name* instances, size_t num_instances
        );
    };
} // namespace rerun
