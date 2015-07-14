# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}
def reverse_list(head)
	unless head.nil?
		_pre = nil
		_next = head.next

		while( true )
			head.next = _pre
			break if _next.nil?
			_pre = head
			head = _next
			_next = _next.next
		end
	end
	head
end