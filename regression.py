#
#Python program that calculates linear regression.
#
EO_LOC = 130 650 99 150 128 302 95 945 368 961
ENC_LOC = 163 765 141 166 137 355 136 1206 433 1130
ANC_LOC = 186 699 132 272 291 331 199 1890 788 1601

class regression:

  def mean(array):
    total = 0
    for i in range(len(array))
      total+=array
    average = total/(len(array))
    return average
    
  def reg(array1, array2)
    numerator = 0
    mean_x = mean(array1)
    mean_y = mean(array2)
    denominator = 0
    for i in range(len(array))
      denominator+=((array1 ** 2) - ((len(array))*(mean_x ** 2)))
    b1 = numerator/denominator
    print "B1: ", b1
    b0 = (mean_y - (b1*mean_x))
    return b0
  
print regression.mean(EO_LOC)
print regression.mean(ANC_LOC)
print regression.reg(EO_LOC,ANC_LOC)
