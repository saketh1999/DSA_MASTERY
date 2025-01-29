class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        # Initialize variables to track the bounding rectangle
        x1 = y1 = float('inf')
        x2 = y2 = float('-inf')
        
        # Initialize a set to track all corner points
        corners = set()
        
        # Initialize total area of small rectangles
        total_area = 0
        
        for rect in rectangles:
            x1_small, y1_small, x2_small, y2_small = rect
            
            # Update the bounding rectangle coordinates
            x1 = min(x1, x1_small)
            y1 = min(y1, y1_small)
            x2 = max(x2, x2_small)
            y2 = max(y2, y2_small)
            
            # Calculate the area of the current rectangle and add to total area
            area = (x2_small - x1_small) * (y2_small - y1_small)
            total_area += area
            
            # Define the four corners of the current rectangle
            current_corners = [
                (x1_small, y1_small),
                (x1_small, y2_small),
                (x2_small, y1_small),
                (x2_small, y2_small)
            ]
            
            # Toggle the corners in the set
            for corner in current_corners:
                if corner in corners:
                    corners.remove(corner)
                else:
                    corners.add(corner)
        
        # Calculate the area of the bounding rectangle
        bounding_area = (x2 - x1) * (y2 - y1)
        
        # Check if the total area matches the bounding area
        if total_area != bounding_area:
            return False
        
        # Check if there are exactly four unique corners in the set
        if len(corners) != 4:
            return False
        
        # Check if the four corners match the bounding rectangle corners
        expected_corners = {(x1, y1), (x1, y2), (x2, y1), (x2, y2)}
        if corners != expected_corners:
            return False
        
        # If all checks pass, return True
        return True