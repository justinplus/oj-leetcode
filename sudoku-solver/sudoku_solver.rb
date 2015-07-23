# @param {Character[][]} board
# @return {Void} Do not return anything, modify board in-place instead.

def sudoku_example
  [
    ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
    ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
    ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
    ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
    ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
    ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
    ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
    ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
    ['.', '.', '.', '.', '8', '.', '.', '7', '9']
  ]
end

class Sudoku
  
  Border = 9
  Block = 3

  def initialize(board, blank='.')
    dump = Marshal.dump(board) 
    @board = Marshal.load(dump) 
    # @original_board = Marshal.load(dump) 
    @blank = blank
    @row_i = 0
    @col_i = 0
  end

  def solve
    # byebug
    @row_i = 0
    @col_i = 0
    st = []

    return false unless valid? 

    return Marshal.load(Marshal.dump(@board)) unless next_blank

    fill_in

    while true 
      if partial_valid?
        st << [@row_i, @col_i]
        if next_blank
          fill_in
        else
          return Marshal.load(Marshal.dump(@board))
        end
      else
        while !fill_in
          @board[@row_i][@col_i] = @blank
          return false if st.empty?
          @row_i, @col_i = st.pop
        end
      end
    end
  end

  def next
    @col_i += 1
    if @col_i == Border 
      @col_i = 0
      @row_i += 1 
    end

    if @row_i == Border
      @row_i = 0 
      false
    else
      true
    end
  end

  def next_blank
    while @board[@row_i][@col_i] != @blank
      return false unless self.next # next -> self.next, self is retained by ruby
    end
    true
  end

  def fill_in
    case @board[@row_i][@col_i] 
    when @blank
      @board[@row_i][@col_i] = '1'
    when Border.to_s
      return false
    else
      @board[@row_i][@col_i].succ!
    end
    true
  end

  def valid?
    for i in Range.new(0, Border, true)
      return false unless row_valid?(i)
      return false unless col_valid?(i)
    end

    for i in Range.new(0, Block, true)
      for j in Range.new(0, Block, true)
        return false unless block_valid?(i, j)
      end
    end

    true

  end

  def partial_valid?
    row_valid? and col_valid? and block_valid?
  end

  def row_valid?(row_i = @row_i)
    @board[row_i].reject{ |item| item == @blank }.uniq!.nil?
  end

  def col_valid?(col_i = @col_i)
    @board.map { |r| r[col_i] }.reject{ |item| item == @blank }.uniq!.nil?
  end

  def block_valid?(row_i = @row_i/Block, col_i = @col_i/Block)
    block = Array.new
    for bi in Range.new(0, Block, true)
      for bj in Range.new(0, Block, true)
        block << @board[row_i*Block+bi][col_i*Block+bj]
      end
    end
    # puts "#{@row_i} #{col_i}"
    # puts @board.inspect
    # puts block.inspect
    block.reject{ |item| item == @blank }.uniq!.nil?
  end

end

def solve_sudoku(board)
  sol = Sudoku.new(board).solve
  for i in 0..8
    board[i] = sol[i]
  end
end

# TODO: Attention
# a=1, b=2 if true <=> a = [1, b=2] if true  
# a, b = 1, 2 if true <=> (a, b = 1, 2) if true 

# Array.dup, Array.clone is shallow clone, use Marshal instead
# What the Array.xxx! will return if no change happen??!!
# Time Limit
# [['.','.','.','.','.','7','.','.','9'],
# ['.','4','.','.','8','1','2','.','.'],
# ['.','.','.','9','.','.','.','1','.'],
# ['.','.','5','3','.','.','.','7','2'],
# ['2','9','3','.','.','.','.','5','.'],
# ['.','.','.','.','.','5','3','.','.'],
# ['8','.','.','.','2','3','.','.','.'],
# ['7','.','.','.','5','.','.','4','.'],
# ['5','3','1','.','7','.','.','.','.']]
