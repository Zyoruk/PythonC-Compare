import sys
import random
import argparse
import timeit
import array


parser = argparse.ArgumentParser(prog='datastructs')
parser.add_argument('structure',metavar='struct',choices=['list','tree','array'], help='Enter possible data structs list, tree, array')
parser.add_argument('data' ,metavar='data',type=int,help='Data')

args = vars(parser.parse_args())

dataSize = args['data']
structure = args['structure']

alldata = range(0,9999999)
start_time = timeit.default_timer()

if structure == 'list':
  print 'Creating the list of {} elements.'.format(dataSize)
  l = []
  cont = 0
  start_time = timeit.default_timer()
  while cont <= dataSize:
    l.append(random.choice(alldata))
    cont +=  1
  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'
 
  number = random.choice(alldata)
  print 'Searching for number {}.'.format(number)
  start_time = timeit.default_timer()
  for element in l:
    if element == number:
      break

  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'


  number = random.choice(alldata)
  print 'Searching for number {} and delete it.'.format(number)
  start_time = timeit.default_timer()
  for element in l:
    if element == number:
      l.remove(number)

  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'

elif structure == 'array':
  print 'Creating the array of {} elements.'.format(dataSize)
  arr = array.array('l')
  cont = 0
  start_time = timeit.default_timer()
  while cont <= dataSize:
    
    arr.append(random.choice(alldata))
    cont +=  1
  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'
 
  number = random.choice(alldata)
  print 'Searching for number {}.'.format(number)
  start_time = timeit.default_timer()
  for element in arr:
    if element == number:
      break

  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'


  number = random.choice(alldata)
  print 'Searching for number {} and delete it.'.format(number)
  start_time = timeit.default_timer()
  for element in arr:
    if element == number:
      arr.remove(number)

  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'
