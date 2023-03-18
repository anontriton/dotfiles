#!/bin/sh

free --mebi | sed -n '2{p;q}' | awk '{printf ("💾%2.2fG/%2.2fG\n", ( $3 / 1000), ($2 / 1000))}'
