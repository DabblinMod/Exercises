class WordSearch:
    #we are tackling a word search problem in a 2D board string array of characters
    #to solve this problem we use BACKTRACKING Algorithim (type of Brute Force)
    
    def exist(self, board:List[List[str]], word: str):
        ROWS, COLS = len(board), len(board[0]) #get the length of row and col for looping
        path = set() #to keep track of the strings we visit
        
        def dfs(r, c, i): #r is row #c is col #i is index of letters
            if (i==len(word)):
                return False
            if(r < 0 or c < 0 or   r>=ROWS or c>=COLS or
                word[i] != board[r][c] or
                (r,c) in path):
                return False
            
            path.add((r,c)) #add r and c to the set
            
           res = (dfs(r+1, c, i+1) or
           dfs(r-1, c, i+1) or
           dfs(r, c+1, i+1) or
           dfs(r, c-1, i+1)) 
           #will take 4 different checks to see if it returns the result from each as true
           path.remove((r,c))
        
        #within exist func() code block
        for r in range(ROWS):
            for c in range(COLS):
                if(dfs(r, c, 0): return True
        return False
