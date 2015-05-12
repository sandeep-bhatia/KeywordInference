#include <memory>
#include "LinearInterpolationSmoothing.h"
#include "Model.h"
#include "LinearInterpolationSmoothingPrivate.h"

using namespace citar::tagger;

namespace citar {
namespace tagger {

LinearInterpolationSmoothing::LinearInterpolationSmoothing(
		std::shared_ptr<Model const> model)
	: d_private (new LinearInterpolationSmoothingPrivate(model))
{
}

LinearInterpolationSmoothing::~LinearInterpolationSmoothing()
{
	delete d_private;
}

double LinearInterpolationSmoothing::triGramProb(TriGram const &triGram) const
{
	return d_private->triGramProb(triGram);
}

}
}