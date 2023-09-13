// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/clear.fbs".

#pragma once

#include "../arrow.hpp"
#include "../component_batch.hpp"
#include "../components/clear_settings.hpp"
#include "../data_cell.hpp"
#include "../result.hpp"

#include <cstdint>
#include <utility>
#include <vector>

namespace rerun {
    namespace archetypes {
        /// Empties all the components of an entity.
        ///
        /// ## Examples
        ///
        /// Flat:
        ///```
        ///// Log a batch of 3D arrows.
        ///
        /// #include <rerun.hpp>
        ///
        /// #include <cmath>
        /// #include <numeric>
        ///
        /// namespace rr = rerun;
        ///
        /// int main() {
        ///    auto rec = rr::RecordingStream("rerun_example_clear_simple");
        ///    rec.connect("127.0.0.1:9876").throw_on_failure();
        ///
        ///    std::vector<rr::components::Vector3D> vectors = {
        ///        {1.0, 0.0, 0.0},
        ///        {0.0, -1.0, 0.0},
        ///        {-1.0, 0.0, 0.0},
        ///        {0.0, 1.0, 0.0},
        ///    };
        ///    std::vector<rr::components::Origin3D> origins = {
        ///        {-0.5, 0.5, 0.0},
        ///        {0.5, 0.5, 0.0},
        ///        {0.5, -0.5, 0.0},
        ///        {-0.5, -0.5, 0.0},
        ///    };
        ///    std::vector<rr::components::Color> colors = {
        ///        {200, 0, 0},
        ///        {0, 200, 0},
        ///        {0, 0, 200},
        ///        {200, 0, 200}};
        ///
        ///    // Log a handful of arrows.
        ///    for (int i = 0; i <vectors.size(); ++i) {
        ///        auto entity_path = "arrows/" + std::to_string(i);
        ///        rec.log(
        ///            entity_path.c_str(),
        ///            rr::Arrows3D(vectors[i]).with_origins(origins[i]).with_colors(colors[i])
        ///        );
        ///    }
        ///
        ///    // Now clear them, one by one on each tick.
        ///    for (int i = 0; i <vectors.size(); ++i) {
        ///        auto entity_path = "arrows/" + std::to_string(i);
        ///        rec.log(entity_path.c_str(), rr::Clear::flat());
        ///    }
        /// }
        ///```
        /// Recursive:
        ///```
        ///// Log a batch of 3D arrows.
        ///
        /// #include <rerun.hpp>
        ///
        /// #include <cmath>
        /// #include <numeric>
        ///
        /// namespace rr = rerun;
        ///
        /// int main() {
        ///    auto rec = rr::RecordingStream("rerun_example_clear_recursive");
        ///    rec.connect("127.0.0.1:9876").throw_on_failure();
        ///
        ///    std::vector<rr::components::Vector3D> vectors = {
        ///        {1.0, 0.0, 0.0},
        ///        {0.0, -1.0, 0.0},
        ///        {-1.0, 0.0, 0.0},
        ///        {0.0, 1.0, 0.0},
        ///    };
        ///    std::vector<rr::components::Origin3D> origins = {
        ///        {-0.5, 0.5, 0.0},
        ///        {0.5, 0.5, 0.0},
        ///        {0.5, -0.5, 0.0},
        ///        {-0.5, -0.5, 0.0},
        ///    };
        ///    std::vector<rr::components::Color> colors = {
        ///        {200, 0, 0},
        ///        {0, 200, 0},
        ///        {0, 0, 200},
        ///        {200, 0, 200}};
        ///
        ///    // Log a handful of arrows.
        ///    for (int i = 0; i <vectors.size(); ++i) {
        ///        auto entity_path = "arrows/" + std::to_string(i);
        ///        rec.log(
        ///            entity_path.c_str(),
        ///            rr::Arrows3D(vectors[i]).with_origins(origins[i]).with_colors(colors[i])
        ///        );
        ///    }
        ///
        ///    // Now clear all of them at once.
        ///    rec.log("arrows", rr::Clear::recursive());
        /// }
        ///```
        struct Clear {
            rerun::components::ClearSettings settings;

            /// Name of the indicator component, used to identify the archetype when converting to a
            /// list of components.
            static const char INDICATOR_COMPONENT_NAME[];

          public:
            // Extensions to generated type defined in 'clear_ext.cpp'

            static Clear flat() {
                return Clear(false);
            }

            static Clear recursive() {
                return Clear(true);
            }

            Clear(bool recursive = false) : Clear(components::ClearSettings(recursive)) {}

          public:
            Clear() = default;

            Clear(rerun::components::ClearSettings _settings) : settings(std::move(_settings)) {}

            /// Returns the number of primary instances of this archetype.
            size_t num_instances() const {
                return 1;
            }

            /// Collections all component lists into a list of component collections. *Attention:*
            /// The returned vector references this instance and does not take ownership of any
            /// data. Adding any new components to this archetype will invalidate the returned
            /// component lists!
            std::vector<AnonymousComponentBatch> as_component_batches() const;
        };
    } // namespace archetypes
} // namespace rerun