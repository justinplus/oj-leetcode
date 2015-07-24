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
  Choices = [ '1', '2', '3', '4', '5', '6', '7', '8', '9' ]

  def initialize(board, blank='.')
    @board = board 
    @blank = blank
    @row_i = 0
    @col_i = 0
    @choices = []
  end

  def solve
    # byebug
    @row_i = 0
    @col_i = 0
    st = []

    return false unless valid? 

    return Marshal.load(Marshal.dump(@board)) unless next_blank

    while true 
      if fill_in
        st << [@row_i, @col_i]
        return Marshal.load(Marshal.dump(@board)) unless next_blank
      else
        @board[@row_i][@col_i] = @blank
        @row_i, @col_i = st.pop
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
    if @board[@row_i][@col_i] == @blank
      row = @board[@row_i].reject{ |item| item == @blank}
      col = @board.map { |r| r[@col_i] }.reject{ |item| item == @blank}
      block = Array.new
      for bi in Range.new(0, Block, true)
        for bj in Range.new(0, Block, true)
          block << @board[@row_i/Block*Block+bi][@col_i/Block*Block+bj]
        end
      end
      block.reject!{ |item| item == @blank }
      choices = Choices - row - col - block
      return false if choices.empty?
      @board[@row_i][@col_i] = choices.shift
      @choices << choices
      true
    else
      if @choices.last.empty?
        @choices.pop
        return false
      else
        @board[@row_i][@col_i] = @choices.last.shift
        return true
      end

    end
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
    block.reject{ |item| item == @blank }.uniq!.nil?
  end

end

def solve_sudoku(board)
  Sudoku.new(board).solve
  nil # TODO: Attention, do not return anything
end

# TODO: Attention
# a=1, b=2 if true <=> a = [1, b=2] if true  
# a, b = 1, 2 if true <=> (a, b = 1, 2) if true 

# Array.dup, Array.clone is shallow clone, use Marshal instead
# What the Array.xxx! will return if no change happen??!!
# Time Limit Exceed
# [['.','.','.','.','.','7','.','.','9'],
# ['.','4','.','.','8','1','2','.','.'],
# ['.','.','.','9','.','.','.','1','.'],
# ['.','.','5','3','.','.','.','7','2'],
# ['2','9','3','.','.','.','.','5','.'],
# ['.','.','.','.','.','5','3','.','.'],
# ['8','.','.','.','2','3','.','.','.'],
# ['7','.','.','.','5','.','.','4','.'],
# ['5','3','1','.','7','.','.','.','.']]
