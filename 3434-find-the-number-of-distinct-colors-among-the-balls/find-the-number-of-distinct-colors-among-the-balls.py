class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ball_to_color = {}
        color_to_ball = defaultdict(int)
        res = []

        for ball,color in queries:
            if ball in ball_to_color:
                prev_color = ball_to_color[ball]
                color_to_ball[prev_color]-=1

                if color_to_ball[prev_color]==0:
                    del color_to_ball[prev_color]
            
            ball_to_color[ball] = color
            color_to_ball[color] = color_to_ball[color]+1

            res.append(len(color_to_ball))
        
        return res
