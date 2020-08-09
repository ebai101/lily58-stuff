#!/usr/bin/env python3

import random

# symbols = '1234567890!@#$%[{]}^&*()|=_-+~/\<>?`"\''
symbols = '1234567890'
for i in range(5):
    print(''.join(random.sample([char for char in symbols], len(symbols))), end=' ')
