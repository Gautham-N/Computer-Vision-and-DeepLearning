# -*- coding: utf-8 -*-
"""ClassificationVGG16.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1dIqPhJh2SIONHZBdN9Yq5xCaaHZ6JSby
"""

#Main Block : Calling libraries, preparing data, Load the parameter
import cv2
import os

import keras
import tensorflow as tf
device_name = tf.test.gpu_device_name()
if device_name != '/device:GPU:0':
  raise SystemError('GPU device not found')
print('Found GPU at: {}'.format(device_name))
from tqdm import tqdm

#Trained using GPU

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_files
from sklearn.preprocessing import LabelBinarizer
from sklearn.metrics import classification_report,accuracy_score
from sklearn.metrics import confusion_matrix
from keras.models import model_from_json

from keras.utils import np_utils
from keras.callbacks import ModelCheckpoint

from keras.preprocessing.image import ImageDataGenerator
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten
from keras.layers import Conv2D, MaxPooling2D, BatchNormalization,GlobalAveragePooling2D
from keras.layers.convolutional import Convolution2D, MaxPooling2D, ZeroPadding2D
from keras import optimizers
from keras.models import Model
from keras.layers import Input
from keras.layers.core import Lambda
from keras import backend as K
from keras import regularizers

#Prepare data set
def load_data(folder_path):
  data = load_files(folder_path)
  #columnnames=os.listdir(folder_path)
  files = np.array(data['filenames'])
  targ = np.array(data['target'])
  return files,targ
fold = 'Image folder path'
img_files,target = load_data(fold)
print(img_files.shape)
def extract(img_file):
  img = plt.imread(img_file)
  img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
  img = cv2.resize(img,(200,200))
  print(img.shape)
  return img

def tensor_4d(fil):
  list_of_tensors = [extract(im) for im in tqdm(fil)]
  return np.stack(list_of_tensors,axis=0)

#Image Normalization and other parameter
imgs = tensor_4d(img_files)
imgs1=imgs.astype('float32')/255
num_classes=len(np.unique(target))
lb = LabelBinarizer()
targets = lb.fit_transform(target)

#Import layer and VGG16 model
from keras.models import Sequential, Model, load_model
from keras import applications
from keras import optimizers
from keras.layers import Dropout, Flatten, Dense

input_size=(200,200,3)

base_model = keras.applications.VGG16(weights='imagenet', include_top=False, input_shape=input_size)

#Adding Softmax activation layer and summary

add_model = Sequential()
add_model.add(Flatten(input_shape=base_model.output_shape[1:]))
add_model.add(Dense(256, activation='relu'))
add_model.add(Dense(3, activation='softmax'))

model = Model(inputs=base_model.input, outputs=add_model(base_model.output))
model.compile(loss='categorical_crossentropy', optimizer=optimizers.SGD(lr=0.0001, momentum=0.9),
              metrics=['accuracy'])

model.summary()

#Train the model 
model.fit(imgs1,targets,batch_size=3,epochs=50,verbose=1,shuffle=True)

#model saving

#model.save_weights("weightsxay.h5")
model.save('modelxay.h5')
model = load_model('modelxay.h5')
print(model.outputs)
# [<tf.Tensor 'dense_2/Softmax:0' shape=(?, 10) dtype=float32>]
print(model.inputs)