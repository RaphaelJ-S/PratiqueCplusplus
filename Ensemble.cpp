#ifndef ENSEMBLE_CPP
#define ENSEMBLE_CPP

#include <vector>

template <class T>
class Ensemble {
	
	std::vector<T> ensemble;

	public:
		
		Ensemble() {
		}
		
		~Ensemble() {
			delete ensemble;
		}
		
		int getIndex(T membre) {
			for (size_t i = 0; i < ensemble.size(); ++i) {
				if (ensemble[i] == membre) return i;
			}
			return -1;
		}

		T getMembre(int index) {
			return ensemble[index];
		}

		std::vector<T>& getEnsemble() {
			return ensemble;
		}

		int ajouteMembre(T nv) {
			if (getIndex(nv) == -1) {
				ensemble.push_back(nv);
				return 0;
			}
			return -1;
		}

		void clear() {
			ensemble.clear();
		}

		int size() {
			return ensemble.size();
		}

};
#endif
