#!/usr/bin/env python
# -*- coding: ISO-8859-1 -*-

import os
import pylibfromCFFI

from flask import Flask
from flask import request
from flask import render_template
#from flask_paginate import Pagination, get_page_parameter

THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))

app 		= Flask(__name__)
app.debug 	= False

@app.after_request
def add_header(r):
	r.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
	r.headers["Pragma"] = "no-cache"
	r.headers["Expires"] = "0"
	r.headers['Cache-Constrol'] = 'public, max-age=0'
	return r

@app.route('/combinacion', methods=['GET']) 
def combinacion():
	
	pylibfromCFFI.combinacionImagenes()
	inputImage = "tigre2.jpg";
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/ecualizacion', methods=['GET']) 
def ecualizacion():
	
	inputImage = "histograma.jpg";
	pylibfromCFFI.ecualizacion(inputImage.encode('ISO-8859-1'))
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/sobel', methods=['GET']) 
def sobel():
	
	inputImage = "kuriboh.jpg";
	pylibfromCFFI.sobel(inputImage.encode('ISO-8859-1'))
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/medianblur', methods=['GET']) 
def medianblur():
	
	inputImage = "kuriboh.jpg";
	pylibfromCFFI.medianblur(inputImage.encode('ISO-8859-1'))
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/difuminadoAleatorio', methods=['GET']) 
def difuminadoAleatorio():
	
	inputImage = "kuriboh.jpg";
	pylibfromCFFI.difuminadoAleatorio(inputImage.encode('ISO-8859-1'))
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/transformacionBilineal', methods=['GET']) 
def transformacionBilineal():
	
	inputImage = "kuriboh.jpg";
	pylibfromCFFI.transformacionBilineal(inputImage.encode('ISO-8859-1'))
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/fft', methods=['GET']) 
def fft():
	
	inputImage = "kuriboh.jpg";
	pylibfromCFFI.fft(inputImage.encode('ISO-8859-1'))
	outputImage = "imagen.jpg";

	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

@app.route('/')
def home():
	inputImage = ""
	outputImage = ""
	return render_template('index.html', inputImage = inputImage, outputImage=outputImage)

if __name__ == '__main__':
	app.config["CACHE_TYPE"] = "null"
	app.run(host='0.0.0.0', port=5000, debug=False)
