class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        color_map = {}
        ball_map = {}
        
        res = []
        for ball, color in queries:
            if ball in ball_map:
                old_color = ball_map[ball]
                color_map[old_color] -= 1
                if color_map[old_color] == 0:
                    del color_map[old_color]
        
            ball_map[ball] = color
            color_map[color] = color_map.get(color, 0) + 1
        
            res.append(len(color_map))
        
        return res
