class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: list[list[int]], queries: list[list[int]]) -> list[bool]:
        mat = [[False] * numCourses for _ in range(numCourses)]
        
        for prereq in prerequisites:
            s, d = prereq
            mat[s][d] = True
        
        for k in range(numCourses):
            for s in range(numCourses):
                for d in range(numCourses):
                    mat[s][d] = mat[s][d] or (mat[s][k] and mat[k][d])
        
        ans = []
        for query in queries:
            s, d = query
            ans.append(mat[s][d])
        
        return ans
