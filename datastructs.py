import sys ,random, argparse, timeit, time, array
import binary_tree

#Create the argument parser
parser = argparse.ArgumentParser(prog='datastructs')
parser.add_argument('structure',metavar='struct',choices=['list','tree','array'], help='Enter possible data structs list, tree, array')
parser.add_argument('data' ,metavar='data',type=int,help='Data')

#Take arguments and transform to iterable
args = vars(parser.parse_args())

#Store arguments
dataSize = args['data']
structure = args['structure']

#List of possible elements to pick
alldata = range(0,9999999)



print 'Creating the {} of {} elements.'.format(structure, dataSize)

if structure == 'list':
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

elif (structure == 'tree'):
  tree = BinarySearchTree()
  cont = 0
  start_time = timeit.default_timer()
  while cont <= dataSize:      
    tree.insert(random.choice(alldata))
    cont +=  1
  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'

  print 'Removing one element from tree'

  start_time = timeit.default_timer()
  while True:
    try:
      tree.pop(number)
      break;
    except:
      number = random.choice(alldata)

  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'


  print 'Searching for one element from tree'

  start_time = timeit.default_timer()
  while True:
    try:
      tree.pop(number)
      break;
    except:
      number = random.choice(alldata)

  elapsed = timeit.default_timer() - start_time
  print 'Took ' + str(elapsed) + ' seconds.'

