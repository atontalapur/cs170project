import numpy as np


def evaluate(features, labels, feature_set):
    feature_list = [feature - 1 for feature in sorted(feature_set)]
    selected_features = features[:, feature_list]
    counter = 0
    for i in range(features.shape[0]):
        nearest_neighbor_euclidian_distance = float("inf")
        nearest_neighbor_label = -1
        for j in range(features.shape[0]):
            if j == i:
                continue
            distance = np.sqrt(
                np.sum((selected_features[i] - selected_features[j]) ** 2)
            )
            if distance < nearest_neighbor_euclidian_distance:
                nearest_neighbor_euclidian_distance = distance
                nearest_neighbor_label = labels[j]
        if nearest_neighbor_label == labels[i]:
            counter += 1

    return counter / features.shape[0] * 100


def forward_selection(features, labels):
    curr_features = set()
    best_feature = set()
    best_accuracy = 0
    previous_level_accuracy = 0

    for i in range(features.shape[1]):
        best_level_accuracy = 0
        best_level_feature = -1
        for feature in range(1, features.shape[1] + 1):
            if feature in curr_features:
                continue
            accuracy = evaluate(features, labels, curr_features | {feature})
            print(
                "Using feature(s) {",
                *sorted(curr_features | {feature}),
                "} accuracy is ",
                accuracy,
                "%",
            )
            if accuracy > best_level_accuracy:
                best_level_accuracy = accuracy
                best_level_feature = feature
        if i > 0 and best_level_accuracy < previous_level_accuracy:
            print(
                "(Warning: Accuracy has decreased! Continuing search in case of local maxima)"
            )
        if best_level_accuracy > best_accuracy:
            best_accuracy = best_level_accuracy
            best_feature = (curr_features | {best_level_feature}).copy()
        if best_level_feature != -1:
            curr_features.add(best_level_feature)
            previous_level_accuracy = best_level_accuracy
        print(
            "Feature set ",
            sorted(best_feature),
            " was the best, accuracy is",
            best_accuracy,
            "%",
        )
    print(
        "Finished search!! The best feature subset is {",
        *sorted(best_feature),
        "} which has an accuracy of ",
        best_accuracy,
        "%",
    )


def backward_elimination(features, labels):
    curr_features = set(range(1, features.shape[1] + 1))
    best_feature = curr_features.copy()
    best_accuracy = evaluate(features, labels, curr_features)

    for i in range(features.shape[1]):
        best_level_accuracy = 0
        worst_level_feature = -1
        for feature in curr_features:
            accuracy = evaluate(features, labels, curr_features - {feature})
            print(
                "Using feature(s) {",
                *sorted(curr_features - {feature}),
                "} accuracy is ",
                accuracy,
                "%",
            )
            if accuracy > best_level_accuracy:
                best_level_accuracy = accuracy
                worst_level_feature = feature

        if best_level_accuracy > best_accuracy:
            best_accuracy = best_level_accuracy
            best_feature = (curr_features - {worst_level_feature}).copy()
        if worst_level_feature != -1:
            curr_features.remove(worst_level_feature)
    print(
        "Finished search!! The best feature subset is {",
        *sorted(best_feature),
        "} which has an accuracy of ",
        best_accuracy,
        "%",
    )


def main():
    print("Welcome to Advaith Tontalapur's Feature Selection Algorithm.")
    filename = input("Type in the name of the file to test: ")
    data = np.loadtxt(filename)
    # print("Data:", data)
    labels = data[:, 0]
    features = data[:, 1:]
    # print("Labels:", labels)
    # print("Features:", features)
    algorithmChoice = input(
        "Type the number of the algorithm you want to run. \n 1) Forward Selection \n 2) Backward Elimination \n"
    )
    print(
        "This data has ",
        features.shape[1],
        "features (not including the class attribute), with ",
        features.shape[0],
        "instances.",
    )
    all_features = set(range(1, features.shape[1] + 1))
    accuracy = evaluate(features, labels, all_features)
    print(
        f"Running nearest neighbor with all {features.shape[1]} features, using 'leaving-one-out' evaluation, I get an accuracy of {accuracy:.1f}%"
    )
    if algorithmChoice == "1":
        forward_selection(features, labels)
    elif algorithmChoice == "2":
        backward_elimination(features, labels)


if __name__ == "__main__":
    main()
