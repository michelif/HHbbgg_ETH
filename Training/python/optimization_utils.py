from sklearn import model_selection
from sklearn.model_selection import train_test_split


    
def optimize_parameters_gridCV(classifier,X_total_train,y_total_train,param_grid,cvOpt=3,nJobs=10):
    print "=====Optimization with grid search cv====="
    scores = model_selection.cross_val_score(classifier,
                                      X_total_train, y_total_train,
                                      scoring="roc_auc",
                                      n_jobs=nJobs,
                                      cv=cvOpt)
    print "-Initial Accuracy-"
    print "Accuracy: %0.5f (+/- %0.5f)"%(scores.mean(), scores.std())

    
    
    X_train, X_test, y_train, y_test = train_test_split(X_total_train, y_total_train)
    
    clf = model_selection.GridSearchCV(classifier,
                                   param_grid,
                                   cv=cvOpt,
                                   scoring='roc_auc',
                                   n_jobs=nJobs, verbose=1)
    clf.fit(X_train, y_train)
    
    print "Best parameter set found on development set:"
    print
    print clf.best_estimator_
    print
    print "Grid scores on a subset of the development set:"
    print
    for params, mean_score, scores in clf.grid_scores_:
        print "%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params)
    
    return clf.grid_scores_



def optimize_parameters_randomizedCV(classifier,X_total_train,y_total_train,param_grid,nIter=10,cvOpt=3,nJobs=10,weights=None):
    print "=====Optimization with randomized search cv====="
    scores = model_selection.cross_val_score(classifier,
                                      X_total_train, y_total_train,
                                      scoring="roc_auc",
                                      n_jobs=nJobs,
                                      cv=cvOpt)
    print "-Initial Accuracy-"
    print "Accuracy: %0.5f (+/- %0.5f)"%(scores.mean(), scores.std())

    
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
    
    print "Best parameter set found on development set:"
    print
    print clf.best_estimator_
    print
    print "Grid scores on a subset of the development set:"
    print
    for params, mean_score, scores in clf.grid_scores_:
        print "%0.4f (+/-%0.04f) for %r"%(mean_score, scores.std(), params)
    
    return clf.grid_scores_

