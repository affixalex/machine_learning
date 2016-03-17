#!/usr/bin/env python3

""" 
  We're going to come up with an extremely simplified model of traffic and
  conversion that we can reason about with TensorFlow. All we're going to do here
  is generate some fake data for our network of sites, users, and conversions.
"""

import json
from faker import Factory
fake = Factory.create()

# In general, create iterators w/ yield for improved memory efficiency
#
# def apply_f(xs):
#   for x in xs: yield f(x)
# ys = apply_f(xs)

# It's a work in progress.
for x in range(0, 100):
	print(fake.url())
