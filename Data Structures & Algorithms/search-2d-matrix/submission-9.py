class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # we want to binary search
        l = 0
        r = len(matrix) * len(matrix[0]) - 1
        while l <= r:
            mid = l + (r - l)//2
            i = mid//len(matrix[0])
            j = mid%len(matrix[0])
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                r = mid - 1;
            else:
                l = mid + 1;
        return False


        