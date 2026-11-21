class Solution:
    def maxDistance(self, position: list[int], m: int) -> int:
        position.sort()
        print(f"position: {position}")

        lo: int = 1 - 1
        hi: int = position[-1] + 1

        while hi - lo > 1:
            mid = lo + (hi - lo) // 2

            last_ball = position[0]
            ball_count = 1
            for i in range(1, len(position)):
                x: int = position[i]
                if x - last_ball >= mid:
                    last_ball = position[i]
                    ball_count += 1

                if ball_count >= m:
                    break

            if ball_count >= m:
                lo = mid
            else:
                hi = mid

        return lo
