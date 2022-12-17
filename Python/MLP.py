import numpy as np
import random
import pandas as pd
from sklearn.model_selection import train_test_split


class MLP:
    def __new__(cls, n_inputs, n_hidden, n_outputs, seeds=1):
        # super().__init__()

        cls.n_inputs = n_inputs
        cls.n_hidden = n_hidden
        cls.n_outputs = n_outputs
        cls.seeds = seeds
        random.seed(cls.seeds)

        network = list()
        cls.network = network

        hidden_layer = [
            {'weights': [random.random() for i in range(n_inputs + 1)]}
            for i in range(n_hidden)]

        network.append(hidden_layer)

        output_layer = [
            {'weights': [random.random() for i in range(n_hidden + 1)]}
            for i in range(n_outputs)]

        network.append(output_layer)

        return network

        # return None
    # Calculate neuron activation for an input

    def activate(self, weights, inputs):

        activation = weights[-1]

        for i in range(len(weights)-1):
            activation += weights[i] * inputs[i]

        return activation

    # Transfer neuron activation
    def transfer(self, activation):
        return 1.0 / (1.0 + np.exp(-activation))

    # Forward propagate input to a network output

    def forward_propagate(self, network, row):
        inputs = row
        for layer in network:
            new_inputs = []
            for neuron in layer:
                activation = self.activate(neuron['weights'], inputs)
                neuron['output'] = self.transfer(activation)
                new_inputs.append(neuron['output'])
            inputs = new_inputs
        return inputs

    # Calculate the derivative of an neuron output
    def transfer_derivative(self, output):
        return output * (1.0 - output)

    # Backpropagate error and store in neurons
    def backward_propagate_error(self, network, expected):
        for i in reversed(range(len(network))):
            layer = network[i]
            errors = list()
            if i != len(network)-1:
                for j in range(len(layer)):
                    error = 0.0
                    for neuron in network[i + 1]:
                        error += (neuron['weights'][j] * neuron['delta'])
                    errors.append(error)
            else:
                for j in range(len(layer)):
                    neuron = layer[j]
                    errors.append(expected[j] - neuron['output'])
            for j in range(len(layer)):
                neuron = layer[j]
                neuron['delta'] = errors[j] * \
                    self.transfer_derivative(neuron['output'])

    # Update network weights with error

    def update_weights(self, network, row, l_rate):
        for i in range(len(network)):
            inputs = row[:-1]
            if i != 0:
                inputs = [neuron['output'] for neuron in network[i - 1]]
            for neuron in network[i]:
                for j in range(len(inputs)):
                    neuron['weights'][j] += l_rate * \
                        neuron['delta'] * inputs[j]
                neuron['weights'][-1] += l_rate * neuron['delta']

    # Train a network for a fixed number of epochs
    def train_network(self, network, dataset, l_rate, n_epoch, n_outputs):
        for epoch in range(n_epoch):
            sum_error = 0
            i = 0
            for row in dataset:
                outputs = self.forward_propagate(network, row)
                expected = [0 for i in range(n_outputs)]
                print("worked", i)
                expected[row[-1]] = 1
                print("!worked")
                i += 1
                sum_error += sum([(expected[i]-outputs[i]) **
                                  2 for i in range(len(expected))])
                self.backward_propagate_error(network, expected)
                self.update_weights(network, row, l_rate)
            print('>epoch=%d, lrate=%.3f, error=%.3f' %
                  (epoch, l_rate, sum_error))

    # Make a prediction with a network
    def predict(self, network, row):
        outputs = forward_propagate(network, row)
        return outputs.index(max(outputs))

    # Backpropagation Algorithm With Stochastic Gradient Descent
    def back_propagation(self, train, test, l_rate, n_epoch, n_hidden):
        n_inputs = len(train[0]) - 1
        n_outputs = len(set([row[-1] for row in train]))
        network = MLP(n_inputs, n_hidden, n_outputs)
        self.train_network(network, train, l_rate, n_epoch, n_outputs)
        predictions = list()
        for row in test:
            prediction = predict(network, row)
            predictions.append(prediction)
        return(predictions)

    def cross_validation_split(self, dataset, n_folds):
        dataset_split = list()
        dataset_copy = list(dataset)
        fold_size = int(len(dataset) / n_folds)
        for i in range(n_folds):
            fold = list()
            while len(fold) < fold_size:
                index = random.randrange(len(dataset_copy))
                fold.append(dataset_copy.pop(index))
            dataset_split.append(fold)
        return dataset_split

    # Calculate accuracy percentage

    def accuracy_metric(self, actual, predicted):
        correct = 0
        for i in range(len(actual)):
            if actual[i] == predicted[i]:
                correct += 1
        return correct / float(len(actual)) * 100.0

    # Evaluate an algorithm using a cross validation split

    def evaluate_algorithm(self, dataset, algorithm, n_folds, *args):
        folds = self.cross_validation_split(dataset, n_folds)
        scores = list()
        for fold in folds:
            train_set = list(folds)
            train_set.remove(fold)
            train_set = sum(train_set, [])
            test_set = list()
            for row in fold:
                row_copy = list(row)
                test_set.append(row_copy)
                row_copy[-1] = None
            predicted = algorithm(train_set, test_set, *args)
            actual = [row[-1] for row in fold]
            accuracy = accuracy_metric(actual, predicted)
            scores.append(accuracy)
        return scores

    def returnValue(self):
        return self.network


df = pd.read_csv("wheat_seeds.csv",
                 names=["First", "Second",
                        "Third", "Fourth", "Fifth",
                        "Sixth", "Seventh", "Answers"])


dataset = []

# Iterate over each row
for index, rows in df.iterrows():

    # Create list for the current row
    my_list = [float(rows.First), float(rows.Second),
               float(rows.Third), float(rows.Fourth),
               float(rows.Fifth), float(rows.Sixth),
               float(rows.Seventh), int(rows.Answers)]

    # # append the list to the final list
    dataset.append(my_list)


n_inputs = len(dataset[0]) - 1
n_outputs = len(set([row[-1] for row in dataset]))

mlp = MLP(n_inputs, 2, n_outputs, 10)
mlp.train_network(mlp.returnValue(), dataset, 0.5, 20, n_outputs)
