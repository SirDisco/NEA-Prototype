#pragma once

#define ETA 5.0f

#include <vector>

#include <Eigen/Dense>

namespace NEA
{
	typedef std::pair<char*, size_t> BinaryData;
	typedef std::pair<Eigen::VectorXf, Eigen::VectorXf> TrainingExample;

	class NeuralNetwork
	{
	public:

		NeuralNetwork(std::vector<size_t> layerSizes);
		NeuralNetwork(char* data);
		virtual ~NeuralNetwork();

	public:

		Eigen::VectorXf FeedForward(Eigen::VectorXf input);
		void Train(std::vector<TrainingExample> trainingData, float eta);

		BinaryData Serialize();

	private:

		void Initialize();

		void Backpropagation(std::vector<Eigen::MatrixXf>& nablaWeights, std::vector<Eigen::VectorXf>& nablaBiases, TrainingExample& example);

		Eigen::VectorXf activationFunctionVector(Eigen::VectorXf& vector);
		Eigen::VectorXf activationFunctionPrimeVector(Eigen::VectorXf& vector);

		static inline float activationFunction(float value);
		static inline float activationFunctionPrime(float value);

	private:

		std::vector<Eigen::MatrixXf> m_Weights;
		std::vector<Eigen::VectorXf> m_Biases;

	};
}