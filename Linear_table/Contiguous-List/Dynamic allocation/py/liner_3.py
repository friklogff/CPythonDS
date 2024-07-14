def InitList(L):
    L.clear()

def DestroyList(L):
    L.clear()

def ListInsert(L, i, e):
    if i < 0 or i > len(L):
        raise IndexError("插入位置错误")
    L.insert(i, e)

def ListDelete(L, i):
    if i < 0 or i >= len(L):
        raise IndexError("删除位置错误")
    del L[i]

def LocateElem(L, e):
    for i, item in enumerate(L):
        if item == e:
            return i
    return -1

def GetElem(L, i):
    if i < 0 or i >= len(L):
        raise IndexError("查找位置错误")
    return L[i]

def Length(L):
    return len(L)

def PrintList(L):
    print(L)

def Empty(L):
    return len(L) == 0

# 测试代码
my_list = []

InitList(my_list)

ListInsert(my_list, 0, 10)
ListInsert(my_list, 1, 20)
ListInsert(my_list, 2, 30)

print("线性表中第一个元素:", GetElem(my_list, 0))
print("线性表的长度:", Length(my_list))
PrintList(my_list)

ListDelete(my_list, 1)
print("线性表的长度:", Length(my_list))
PrintList(my_list)
