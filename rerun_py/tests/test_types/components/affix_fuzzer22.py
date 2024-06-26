# DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/python.rs
# Based on "crates/re_types/definitions/rerun/testing/components/fuzzy.fbs".

# You can extend this class by creating a "AffixFuzzer22Ext" class in "affix_fuzzer22_ext.py".

from __future__ import annotations

from rerun._baseclasses import ComponentBatchMixin

from .. import datatypes

__all__ = ["AffixFuzzer22", "AffixFuzzer22Batch", "AffixFuzzer22Type"]


class AffixFuzzer22(datatypes.AffixFuzzer22):
    # You can define your own __init__ function as a member of AffixFuzzer22Ext in affix_fuzzer22_ext.py

    # Note: there are no fields here because AffixFuzzer22 delegates to datatypes.AffixFuzzer22
    pass


class AffixFuzzer22Type(datatypes.AffixFuzzer22Type):
    _TYPE_NAME: str = "rerun.testing.components.AffixFuzzer22"


class AffixFuzzer22Batch(datatypes.AffixFuzzer22Batch, ComponentBatchMixin):
    _ARROW_TYPE = AffixFuzzer22Type()
