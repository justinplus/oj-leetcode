# @param {Character[][]} board
# @return {Boolean}

Blank = '.'

def is_valid_sudoku(board)  
  for i in Range.new(0, 8)
    # valid ith row
    row = board[i].reject{ |item| item == Blank }
    unique = row.uniq
    return false unless unique == row
    
    # valid ith col
    col = board.map { |r| r[i] }
    unique = col.reject!{ |item| item == Blank }.uniq
    return false unless unique == col
  end

  for i in 0..2
    for j in 0..2
      # valid ith block
      block = Array.new
      for bi in Range.new(0, 2)
        for bj in Range.new(0, 2)
          block << board[i*3+bi][j*3+bj]
        end
      end
      unique = block.reject!{ |item| item == Blank }.uniq
      return false unless unique == block
    end
  end

  true
end

