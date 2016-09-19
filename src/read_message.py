#!/usr/bin/env python3

import msgpack
import sys

with open(sys.argv[1], 'rb') as f:
    data = msgpack.load(f)
    print(data)
