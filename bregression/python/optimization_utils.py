from sklearn import model_selection
from sklearn.model_selection import train_test_split
import numpy as np



# -------------------------------------------------------------------------------------
def setupJoblib(ipp_profile='default'):
    from sklearn.externals.joblib import Parallel, parallel_backend, register_parallel_backend

    import ipyparallel as ipp
    from ipyparallel import Client
    from ipyparallel.joblib import IPythonParallelBackend
    global joblib_rc,joblib_view,joblib_be
    joblib_rc = ipp.Client(profile=ipp_profile)
    joblib_view = joblib_rc.load_balanced_view()
    joblib_be = IPythonParallelBackend(view=joblib_view)

    register_parallel_backend('ipyparallel',lambda : joblib_be,make_default=True)

def setupJoblib_my(ipp_profile='default'):
    from sklearn.externals.joblib import Parallel, parallel_backend, register_parallel_backend

    import ipyparallel as ipp
    from ipyparallel import Client
    from ipyparallel.joblib import IPythonParallelBackend
    global joblib_rc,joblib_view,joblib_be
    joblib_rc = ipp.Client(profile=ipp_profile)
    joblib_view = joblib_rc.load_balanced_view()
    joblib_be = IPythonParallelBackend(view=joblib_view)

    register_parallel_backend('ipyparallel',lambda : joblib_be)


def optimize_parameters_randomizedCV_reg(classifier,X_features,X_target,X_features_test,X_target_test,param_grid,scoring_func, nIter=20,cvOpt=5,nJobs=20,refit=True,weights=None):
    print("=====Optimization with randomized search cv=====")
    
    clf = model_selection.RandomizedSearchCV(classifier,
                                   param_grid,
                                   n_iter=nIter,
                                   cv=cvOpt,
                                 #  scoring='neg_mean_squared_error',
                                 #  scoring='r2',
                                   scoring=scoring_func,
                               #    n_jobs=nJobs, verbose=50,refit=refit,fit_params={'sample_weight': weights})
                                   n_jobs=nJobs, verbose=50,refit=refit)
    clf.fit(X_features, X_target)
    if refit==True:
        print("Best parameter set found on development set:")
        print()
        print(clf.best_estimator_)
    print()
    print("Grid scores on a subset of the development set:")
    print()
    for params, mean_score, scores in clf.grid_scores_:
        print("%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params))
  #  print clf.cv_results_

    return clf



def optimize_parameters_gridCV_reg(classifier,X_features,X_target,X_features_test,X_target_test,param_grid,cvOpt=5,nJobs=2):
    print("=====Optimization with grid search cv=====")
  #  scores = model_selection.cross_val_score(classifier,
   #                                   X_features,X_target,
   #                                   scoring="neg_mean_squared_error", 
   #                                   n_jobs=nJobs,
   #                                   cv=cvOpt)
  #  print "-Initial Accuracy-"
  #  print "Accuracy: %0.5f (+/- %0.5f)"%(scores.mean(), scores.std())

    
        
    clf = model_selection.GridSearchCV(classifier,
                                   param_grid,
                                   cv=cvOpt,
                                   scoring='neg_mean_squared_error',
                                   n_jobs=nJobs, verbose=1)
    clf.fit(X_features, X_target)
    
    print("Best parameter set found on development set:")
    print()
    print(clf.best_estimator_)
    print()
    print("Grid scores on a subset of the development set:")
    print()
    for params, mean_score, scores in clf.cv_results_:
        print("%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params))
    
#    return clf.grid_scores_
    return clf.cv_results_



    
def optimize_parameters_gridCV(classifier,X_total_train,y_total_train,param_grid,cvOpt=3,nJobs=10):
    print("=====Optimization with grid search cv=====")
    scores = model_selection.cross_val_score(classifier,
                                      X_total_train, y_total_train,
                                      scoring="roc_auc",
                                      n_jobs=nJobs,
                                      cv=cvOpt)
    print("-Initial Accuracy-")
    print("Accuracy: %0.5f (+/- %0.5f)"%(scores.mean(), scores.std()))

    
    
    X_train, X_test, y_train, y_test = train_test_split(X_total_train, y_total_train)
    
    clf = model_selection.GridSearchCV(classifier,
                                   param_grid,
                                   cv=cvOpt,
                                   scoring='roc_auc',
                                   n_jobs=nJobs, verbose=1)
    clf.fit(X_train, y_train)
    
    print("Best parameter set found on development set:")
    print()
    print(clf.best_estimator_)
    print()
    print("Grid scores on a subset of the development set:")
    print()
    for params, mean_score, scores in clf.cv_results_:
        print("%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params))
    
    return clf.cv_results_



def optimize_parameters_randomizedCV(classifier,X_total_train,y_total_train,param_grid,nIter=10,cvOpt=3,nJobs=10,weights=None):
    print("=====Optimization with randomized search cv=====")
    scores = model_selection.cross_val_score(classifier,
                                      X_total_train, y_total_train,
                                      scoring="roc_auc",
                                      n_jobs=nJobs,
                                      cv=cvOpt)
    print("-Initial Accuracy-")
    print("Accuracy: %0.5f (+/- %0.5f)"%(scores.mean(), scores.std()))

    
    X_train, X_test, y_train, y_test = train_test_split(X_total_train, y_total_train)
    
    if weights == None:
        clf = model_selection.RandomizedSearchCV(classifier,
                                   param_grid,
                                   n_iter=nIter,
                                   cv=cvOpt,
                                   scoring='roc_auc',
                                   n_jobs=nJobs, verbose=1)
    else:
        clf = model_selection.RandomizedSearchCV(classifier,
                                   param_grid,
                                   n_iter=nIter,
                                   cv=cvOpt,
                                   scoring='roc_auc',
                                   n_jobs=nJobs, verbose=1,
                                   fit_params={'sample_weight': weights})
    clf.fit(X_train, y_train)
    
    print("Best parameter set found on development set:")
    print()
    print(clf.best_estimator_)
    print()
    print("Grid scores on a subset of the development set:")
    print()
    for params, mean_score, scores in clf.cv_results_:
        print("%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params))
    
    return clf.cv_results_



def feature_importances_(self):
  ###  feature_importances_ : array of shape = [n_features]
#    b = self.booster()
    b = self._Booster
    fs = b.get_fscore()
    all_features = [fs.get(f, 0.) for f in b.feature_names]
    all_features = np.array(all_features, dtype=np.float32)
    return all_features / all_features.sum()

