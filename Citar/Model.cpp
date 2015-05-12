#include <fstream>
#include <memory>
#include "Model.h"
#include "ModelPrivate.h"

namespace citar {

	namespace tagger {

		Model::Model(ModelPrivate *model) : d_private(model)
		{
		}

		Model::~Model()
		{
			delete d_private;
		}

		BiGramFreqs const &Model::biGrams() const
		{
			return d_private->biGrams();
		}


		WordTagFreqs const &Model::lexicon() const
		{
			return d_private->lexicon();
		}

		std::unordered_map<size_t, std::string> const &Model::numberTags() const
		{
			return d_private->numberTags();
		}
		std::unordered_map<std::string, size_t> const &Model::tagNumbers() const
		{
			return d_private->tagNumbers();
		}

		TriGramFreqs const &Model::triGrams() const
		{
			return d_private->triGrams();
		}

		UniGramFreqs const &Model::uniGrams() const
		{
			return d_private->uniGrams();
		}


		std::shared_ptr<Model> Model::readModel(std::istream &lexiconStream, std::istream &nGramStream)
		{
			return std::shared_ptr<Model>(
				new Model(ModelPrivate::readModel(lexiconStream, nGramStream)));
		}

	}
}