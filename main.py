import numpy

`


def main():
    print("Welcome to Advaith Tontalapur's Feature Selection Algorithm.")
    filename = input("Type in the name of the file to test: ")
    data = numpy.loadtxt(filename)
    # print("Data:", data)
    labels = data[:, 0]
    features = data[:, 1:]
    # print("Labels:", labels)
    # print("Features:", features)
    algorithmChoice = input("Type the number of the algorithm you want to run. \n 1) Forward Selection \n 2) Backward Elimination \n")
    print("This data has ", features.shape[1], "features (not including the class attribute), with ", features.shape[0], "instances.")



if __name__ == "__main__":
    main()
