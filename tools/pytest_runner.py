import sys
import pytest

if __name__ == "__main__":
    # Remove executable name and run pytest
    args = sys.argv[1:]
    sys.exit(pytest.main(args))
