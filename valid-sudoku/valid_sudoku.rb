# @param {Character[][]} board
# @return {Boolean}

Blank = '.'

def is_valid_sudoku(board)  
  for i in Range.new(0, 8)
    # valid ith row
    return false unless board[i].reject{ |item| item == Blank }.uniq!.nil?
    # valid ith col
    return false unless board.map { |r| r[i] }.reject{ |item| item == Blank }.uniq!.nil?
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
      return false unless block.reject{ |item| item == Blank }.uniq!.nil?
    end
  end

  true
end
