"""Test cases for the canCompleteCircuit function."""

import pytest
from gas_station import canCompleteCircuit


@pytest.mark.parametrize(
    "gas, cost, expected",
    [
        ([1, 2, 3, 4, 5], [3, 4, 5, 1, 2], 3),  # Basic example 1
        ([2, 3, 4], [3, 4, 3], -1),  # Basic example 2
        ([2], [2], 0),  # Single element possible
        ([2], [3], -1),  # Single element impossible
    ],
    ids=[
        "basic_example_1",
        "basic_example_2",
        "single_element_possible",
        "single_element_impossible",
    ],
)
def test_can_complete_circuit(gas: list[int], cost: list[int], expected: int) -> None:
    assert canCompleteCircuit(gas, cost) == expected
