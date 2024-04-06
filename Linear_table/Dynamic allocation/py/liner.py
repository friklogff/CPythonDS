class StaticLinearList:
    def __init__(self):
        self.data = []
        self.length = 0

    def InitList(self):
        self.data = []
        self.length = 0

    def DestroyList(self):
        self.data = []
        self.length = 0

    def ListInsert(self, i, e):
        if i < 0 or i > self.length:
            raise IndexError("插入位置错误")
        self.data.insert(i, e)
        self.length += 1

    def ListDelete(self, i):
        if i < 0 or i >= self.length:
            raise IndexError("删除位置错误")
        self.data.pop(i)
        self.length -= 1

    def LocateElem(self, e):
        for i, item in enumerate(self.data):
            if item == e:
                return i
        return -1

    def GetElem(self, i):
        if i < 0 or i >= self.length:
            raise IndexError("查找位置错误")
        return self.data[i]

    def Length(self):
        return self.length

    def PrintList(self):
        print(self.data)

    def Empty(self):
        return self.length == 0


# 测试代码
list = StaticLinearList()

list.InitList()
list.ListInsert(0, 10)
list.ListInsert(1, 20)
list.ListInsert(2, 30)

print("线性表中第一个元素:", list.GetElem(0))
print("线性表的长度:", list.Length())
list.PrintList()

list.ListDelete(1)
print("线性表的长度:", list.Length())
list.PrintList()
