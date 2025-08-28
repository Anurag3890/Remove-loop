class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

def remove_loop(head):
    slow=fast=head
    loop=False
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
        if slow==fast: loop=True; break
    if not loop: return
    slow=head
    if slow==fast:  # loop starts at head
        while fast.next!=slow: fast=fast.next
    else:
        while slow.next!=fast.next: slow=slow.next; fast=fast.next
    fast.next=None

def print_list(head):
    temp=head
    while temp: print(temp.data,end=" "); temp=temp.next
    print()

head=Node(10)
second=Node(20)
third=Node(30)
head.next=second
second.next=third
third.next=second  # loop
remove_loop(head)
print_list(head)
