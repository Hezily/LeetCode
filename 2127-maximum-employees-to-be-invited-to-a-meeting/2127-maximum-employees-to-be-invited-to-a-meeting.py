class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        longest_cycle = 0
        two_len_cycles = []
        visited = [False] * n

        # Find cycles (len > 2) and collect 2-length cycles
        for i in range(n):
            if visited[i]:
                continue

            seen = set()
            start = i
            cur = i

            while not visited[cur]:
                visited[cur] = True
                seen.add(cur)
                cur = favorite[cur]

            cycle_len = len(seen)
            while start != cur:
                cycle_len -= 1
                start = favorite[start]

            longest_cycle = max(longest_cycle, cycle_len)

            if cycle_len == 2:
                two_len_cycles.append((cur, favorite[cur]))

        # Create reverse adjacency list
        reverse_list = defaultdict(list)
        for i in range(n):
            reverse_list[favorite[i]].append(i)

        # Helper function to find the longest path ignoring a specific node
        def find_longest_path(node, skip):
            max_len = 0
            queue = deque([(node, 0)])

            while queue:
                cur_node, cur_len = queue.popleft()
                max_len = max(max_len, cur_len)
                for neighbor in reverse_list[cur_node]:
                    if neighbor == skip:
                        continue
                    queue.append((neighbor, cur_len + 1))

            return max_len

        max_two_len_cycle_path = 0
        for x, y in two_len_cycles:
            max_two_len_cycle_path += (
                find_longest_path(x, y) + find_longest_path(y, x) + 2
            )

        return max(max_two_len_cycle_path, longest_cycle)
