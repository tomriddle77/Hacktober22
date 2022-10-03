import numpy as np
from keras.models import Sequential
from keras.layers import Dropout, Dense, Flatten
from keras.optimizers import SGD
from keras.layers.convolutional import Conv2D, MaxPooling2D
from keras.utils import np_utils as u
from keras.datasets import cifar10

#Lets start by loading the Cifar10 data
(X, y), (X_test, y_test) = cifar10.load_data()

#Keep in mind the images are in RGB
#So we can normalise the data by diving by 255
#The data is in integers therefore we need to convert them to float first
X, X_test = X.astype('float32')/255.0, X_test.astype('float32')/255.0

#Then we convert the y values into one-hot vectors
#The cifar10 has only 10 classes, thats is why we specify a one-hot
#vector of width/class 10
y, y_test = u.to_categorical(y, 10), u.to_categorical(y_test, 10)

#Now we can go ahead and create our Convolution model
model = Sequential()
#We want to output 32 features maps. The kernel size is going to be
#3x3 and we specify our input shape to be 32x32 with 3 channels
#Padding=same means we want the same dimensional output as input
#activation specifies the activation function
model.add(Conv2D(32, (3, 3), input_shape=(32, 32, 3), padding='same',
                 activation='relu'))
#20% of the nodes are set to 0
model.add(Dropout(0.2))
#now we add another convolution layer, again with a 3x3 kernel
#This time our padding=valid this means that the output dimension can
#take any form
model.add(Conv2D(32, (3, 3), activation='relu', padding='valid'))
#maxpool with a kernet of 2x2
model.add(MaxPooling2D(pool_size=(2, 2)))
#In a convolution NN, we neet to flatten our data before we can
#input it into the ouput/dense layer
model.add(Flatten())
#Dense layer with 512 hidden units
model.add(Dense(512, activation='relu'))
#this time we set 30% of the nodes to 0 to minimize overfitting
model.add(Dropout(0.3))
#Finally the output dense layer with 10 hidden units corresponding to
#our 10 classe
model.add(Dense(10, activation='softmax'))
#Few simple configurations
model.compile(loss='categorical_crossentropy',
              optimizer=SGD(momentum=0.5, decay=0.0004), metrics=['accuracy'])
#Run the algorithm!
model.fit(X, y, validation_data=(X_test, y_test), epochs=25,
          batch_size=512)
#Save the weights to use for later
model.save_weights("cifar10.hdf5")
#Finally print the accuracy of our model!
print("Accuracy: &2.f%%" %(model.evaluate(X_test, y_test)[1]*100))
#print(model.predict_classes(X[0:1]))
#Prints out a number
#1 - airplane, 2 - automobile, 3 - bird, 4 - cat, 5 - deer, 6 - dog
#7 - frog, 8 - horse, 9 - ship, 10 - truck
