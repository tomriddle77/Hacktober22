class Solution {
    public List<List<String>> solveNQueens(int n) {
        //create the chess board
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = '.';
        
        // list to store the final answer
        List<List<String>> ans = new ArrayList<>();
        backtrack (0, board, ans);
        return ans;
    }
    
    public void backtrack (int col, char[][] board, List<List<String>> ans) {
        // base case
        if (col == board.length) {
            List<String> ds = new ArrayList<>();
            for (int i = 0; i < board.length; i++) {
                String s = new String(board[i]);
                ds.add(s);
            }
            ans.add(ds);
            return;
        }
        // check if you can place a queen in that particular position or not
        for (int row = 0; row < board.length; row++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
				// if not then backtrack to its original state
                backtrack(col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    
    public boolean isSafe(int row, int col, char[][] board) {
        // store in different variables bcz we're gonna make changes in row and col
        // and we will further need the original values of row and col 
        int r= row;
        int c = col;
        
        // Note- We are not checking anything on the right bcz we have to place a queen on the right col
        
        // check if Q can attack to its straight left 
        while (col >= 0) {
            if (board[row][col] == 'Q') 
                return false;
            col--;
        }
        
        //  check if Q can attack to its upper left diagonal
        row = r;
        col = c;
        while (row >= 0 && col >=0) {
            if (board[row][col] == 'Q') 
                return false;
            row--;
            col--;
        }
        
        //  check if Q can attack to its lower left diagonal
        row = r;
        col = c;
        while (row < board.length && col >=0) {
            if (board[row][col] == 'Q') 
                return false;
            row++;
            col--;
        }
        
        return true;
    }
}
