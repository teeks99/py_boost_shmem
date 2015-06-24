import ctypes

MAX_ENTITIES = 30


class State(ctypes.Structure):
    _fields_ = [
        ('x', ctypes.c_double),
        ('y', ctypes.c_double),
        ('z', ctypes.c_double)
    ]


class Stat(ctypes.Structure):
    _fields_ = [
        ('numAvailable', ctypes.c_uint),
        ('numUsed', ctypes.c_uint)
    ]


class TransferData(ctypes.Structure):
    _fields_ = [
        ('exLg', ctypes.c_double),
        ('other', ctypes.c_float),
        ('more', ctypes.c_uint),
        ('more2', ctypes.c_int),
        ('next', ctypes.c_ubyte),
        ('statusReady', ctypes.c_bool),
        ('status', Stat),
        ('entities', State * MAX_ENTITIES)
    ]


PY_OFF = 2000

def fill(data):
    data.exLg = PY_OFF + 1.0
    data.other = PY_OFF + 2.0
    data.more = PY_OFF + 3
    data.more2 = PY_OFF + 4
    data.next = 5
    data.statusReady = True

    data.status.numAvailable = PY_OFF + 7
    data.status.numUsed = PY_OFF + 8

    index = 9
    for i in range(MAX_ENTITIES):
        data.entities[i].x = PY_OFF + index
        index += 1
        data.entities[i].y = PY_OFF + index
        index += 1
        data.entities[i].z = PY_OFF + index
        index += 1


def print_entity(data, number):
    e = data.entities[number]
    print('entities[' + str(number) + ']: ' + str(e.x) + ' ' + str(e.y) +
          ' ' + str(e.z))


def print_data(data):
    print('exLg: ' + str(data.exLg))
    print('other: ' + str(data.other))
    print('more: ' + str(data.more))
    print('more2: ' + str(data.more2))
    print('next: ' + str(data.next))
    print('statusReady: ' + str(data.statusReady))
    print('numAvailable: ' + str(data.status.numAvailable))
    print('numUsed: ' + str(data.status.numUsed))
    print_entity(data, 0)
    print_entity(data, 1)
    print_entity(data, 15)
    print_entity(data, MAX_ENTITIES - 1)