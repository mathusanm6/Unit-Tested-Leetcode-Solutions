def trap(height: list[int]) -> int:
    stack = []  # Stores indices in decreasing height order
    water = 0

    for current in range(len(height)):
        # While the current bar is taller than the stack top, a basin is closed
        while stack and height[current] > height[stack[-1]]:
            top = stack.pop()

            if not stack:
                break

            left = stack[-1]
            distance = current - left - 1
            bounded_height = min(height[left], height[current]) - height[top]
            water += distance * bounded_height

        stack.append(current)

    return water
