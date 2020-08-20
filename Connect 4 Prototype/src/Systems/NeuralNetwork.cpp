#include "NeuralNetwork.h"

namespace NEA
{
	NeuralNetwork::NeuralNetwork(std::vector<size_t> layerSizes)
	{
		// Creating the array of weights and bias matrices for easy multiplication
		m_Weights.reserve(layerSizes.size() - 1);
		m_Biases.reserve(layerSizes.size() - 1);

		for (int i = 1; i < layerSizes.size(); i++)
		{
			m_Weights.emplace_back(Eigen::MatrixXf(layerSizes[i], layerSizes[i - 1]));
			m_Biases.emplace_back(Eigen::VectorXf(layerSizes[i], 1));	
		}

		Initialize();
	}

	NeuralNetwork::~NeuralNetwork()
	{
	}

	Eigen::VectorXf NeuralNetwork::FeedForward(Eigen::VectorXf input)
	{
		for (int i = 0; i < m_Weights.size(); i++)
		{
			input = m_Weights[i] * input + m_Biases[i];
			input = activationFunctionVector(input);
		}

		return input;
	}

	// Go through set of training examples and use backpropagation to train the network
	void NeuralNetwork::Train(std::vector<TrainingExample> trainingData, float eta)
	{
		// Changes to all weights and biases
		std::vector<Eigen::MatrixXf> nablaWeights(m_Weights.size());
		std::vector<Eigen::VectorXf> nablaBiases(m_Biases.size());

		// Initialize all nablas to 0
		for (int i = 0; i < m_Weights.size(); i++)
		{
			nablaWeights[i] = Eigen::MatrixXf::Zero(m_Weights[i].rows(), m_Weights[i].cols());
			nablaBiases[i] = Eigen::VectorXf::Zero(m_Biases[i].rows(), m_Biases[i].cols());
		}

		// Backpropagation happens here (updates the current nabla weights and nabla biases)
		for (TrainingExample& example : trainingData)
			Backpropagation(nablaWeights, nablaBiases, example);

		// Update weights and biases by nabla weights and nabla biases
		float scalar = eta / trainingData.size();

		for (int i = 0; i < m_Weights.size(); i++)
		{
			m_Weights[i] -= scalar * nablaWeights[i];
			m_Biases[i] -= scalar * nablaBiases[i];
		}
	}

	void NeuralNetwork::Initialize()
	{
		// For now setting all weights and biases to random values initially
		for (int i = 0; i < m_Weights.size(); i++)
		{
			m_Weights[i].setRandom();
			m_Biases[i].setRandom();
		}
	}

	void NeuralNetwork::Backpropagation(std::vector<Eigen::MatrixXf>& nablaWeights, std::vector<Eigen::VectorXf>& nablaBiases, TrainingExample& example)
	{
		// Changes to all weights and biases
		std::vector<Eigen::MatrixXf> deltaWeights(m_Weights.size());
		std::vector<Eigen::VectorXf> deltaBiases(m_Biases.size());

		// Initialize all deltas to 0
		for (int i = 0; i < m_Weights.size(); i++)
		{
			deltaWeights[i] = Eigen::MatrixXf::Zero(m_Weights[i].rows(), m_Weights[i].cols());
			deltaBiases[i] = Eigen::VectorXf::Zero(m_Biases[i].rows(), m_Biases[i].cols());
		}

		// Feed forward and save all activation and z values
		std::vector<Eigen::VectorXf> activations(m_Weights.size() + 1);
		std::vector<Eigen::VectorXf> zvalues(m_Weights.size() + 1);

		activations[0] = example.first;

		for (int i = 0; i < m_Weights.size(); i++)
		{
			zvalues[i + 1] = m_Weights[i] * activations[i] + m_Biases[i];
			activations[i + 1] = activationFunctionVector(zvalues[i + 1]);
			zvalues[i + 1] = activationFunctionPrimeVector(zvalues[i + 1]);
		}

		// Backpropagate through the network calculating the changes to the weights and biases
		Eigen::VectorXf cost = (activations[activations.size() - 1] - example.second).array() * zvalues[zvalues.size() - 1].array();

		deltaBiases[deltaBiases.size() - 1] = cost;
		deltaWeights[deltaWeights.size() - 1] = cost * activations[activations.size() - 2].transpose();

		for (int i = m_Weights.size() - 2; i >= 0; i--)
		{
			cost = m_Weights[i + 1].transpose() * cost;
			cost = cost.array() * zvalues[i + 1].array();

			deltaBiases[i] = cost;
			deltaWeights[i] = cost * activations[i].transpose();
		}

		// Update nabla weights and biases for total change to weights and biases
		for (int i = 0; i < deltaWeights.size(); i++)
		{
			nablaWeights[i] += deltaWeights[i];
			nablaBiases[i] += deltaBiases[i];
		}
	}

	// Applys the activation function to each element in the vector
	Eigen::VectorXf NeuralNetwork::activationFunctionVector(Eigen::VectorXf& vector)
	{
		return vector.unaryExpr(&activationFunction);
	}

	// Applys the activation function's derivative to each element in the vector
	Eigen::VectorXf NeuralNetwork::activationFunctionPrimeVector(Eigen::VectorXf& vector)
	{
		return vector.unaryExpr(&activationFunctionPrime);
	}

	float NeuralNetwork::activationFunction(float value)
	{
		// For now is the sigmoid function
		return 1.0f / (1 + exp(-value));
	}

	float NeuralNetwork::activationFunctionPrime(float value)
	{
		// For now is the derivative of the sigmoid function
		float sigmoid = activationFunction(value);
		return sigmoid * (1 - sigmoid);
	}
}