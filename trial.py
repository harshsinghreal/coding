class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self.items) == 0

    def top(self):
        if self.is_empty():
            return None
        else:
            return self.items[-1]


def main():
    r_stack = Stack()
    u_stack = Stack()
    r_val = 0
    u_val = 0
    x_val = 0
    num = int(input())
    for i in range(num):
        garbage = int(input())
        r_stack.push(garbage)

    while not r_stack.is_empty():
        garbage = r_stack.pop()
        if u_stack.is_empty() or garbage <= u_stack.top():
            u_stack.push(garbage)
            r_val += 1
        elif u_stack.size() > 1 and garbage > u_stack.top():
            u_garbage = u_stack.pop()
            if garbage <= u_stack.top():
                u_stack.push(garbage)
            else:
                r_stack.push(garbage)
                u_val += 1
                x_val += 1
        elif u_stack.size() == 1 and garbage > u_stack.top():
            u_garbage = u_stack.pop()
            x_val += 1
            u_stack.push(garbage)
            r_stack.push(u_garbage)

    print(f"{r_val} {u_val} {x_val}")


if __name__ == "__main__":
    main()
