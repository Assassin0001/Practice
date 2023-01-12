import streamlit as st
import pandas as pd
from sklearn import datasets
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier

st.write("""
# Simple Wine Quality Prediction App
This app predicts the **Wine Class** Type!
""")

st.sidebar.header('User Input Parameters')

def user_input_features():
    alcohol = st.sidebar.slider('alcohol', 11.0, 14.8, 5.4)
    malic_acid = st.sidebar.slider('malic acid', 0.74, 5.8, 3.4)
    ash = st.sidebar.slider('ash', 1.36, 3.26, 2.5)
    alcalinity_of_ash = st.sidebar.slider('alcalinity_of_ash', 10.6, 30.0, 0.2)
    magnesium = st.sidebar.slider('magnesium', 70.0, 162.0, 99.7)
    total_phenols =st.sidebar.slider('total phenols',0.98,3.88,2.29)
    flavanoids= st.sidebar.slider('flavanoids', 0.34, 5.08, 1.3)
    nonflavanoid_phenols = st.sidebar.slider('nonflavanoid_phenols', 0.13, 0.66, 0.36)
    proanthocyanins= st.sidebar.slider(' proanthocyanins', 0.41, 3.58, 1.59)
    color_intensity = st.sidebar.slider('color_intensity', 1.3, 13.0, 5.1)
    hue = st.sidebar.slider('hue', 0.48, 1.71, 0.96)
    od280od315_of_diluted_wines =  st.sidebar.slider('od280/od315_of_diluted_wines', 1.27, 4.0, 2.61)
    proline = st.sidebar.slider('proline',278,1680,746)

    data = {'alcohol': alcohol,
            'malc_acid': malic_acid,
            'ash': ash,
            'alcalinity_of_ash': alcalinity_of_ash,
            'magnesium': magnesium,
            'total_phenols':total_phenols,
            'flavanoids': flavanoids,
            'nonflavanoid_phenols': nonflavanoid_phenols,
            'proanthocyanins':  proanthocyanins,
            'color_intensity': color_intensity,
            'hue': hue,
            'od280/od315_of_diluted_wines': od280od315_of_diluted_wines,
            'proline': proline
            }
    features = pd.DataFrame(data, index=[0])
    return features

df = user_input_features()

st.subheader('User Input parameters')
st.write(df)

wine = datasets.load_wine()
X=wine.data
Y=wine.target


clf = RandomForestClassifier()
clf.fit(X, Y)

prediction = clf.predict(df)
prediction_proba = clf.predict_proba(df)

st.subheader('Class labels and their corresponding index number')
st.write(wine.target_names)

st.subheader('Prediction')
st.write('According to RandomForest Classifier:-')
st.write(wine.target_names[prediction])

st.subheader('Prediction Probability')
st.write(prediction_proba)